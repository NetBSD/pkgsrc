# $NetBSD: enigmail.mk,v 1.14 2015/03/14 23:02:52 tnn Exp $
#
# This Makefile fragment hooks the Enigmail OpenPGP extension
# (see http://www.mozilla-enigmail.org/ ) into the build.

ENIGMAIL_DIST=		enigmail-1.7.2.tar.gz
XPI_FILES+=		${WRKDIR}/enigmail.xpi
.if !defined(DISTFILES)
DISTFILES=		${DEFAULT_DISTFILES}
.endif
DISTFILES+=		${ENIGMAIL_DIST}
SITES.${ENIGMAIL_DIST}=	http://www.mozilla-enigmail.org/download/source/

REPLACE_PERL+=		mailnews/extensions/enigmail/util/fixlang.pl

DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
PLIST_SRC+=		PLIST.enigmail

TARGET_XPCOM_ABI=	${MACHINE_ARCH:S/i386/x86/}-gcc3
PLIST_SUBST+=		TARGET_XPCOM_ABI=${TARGET_XPCOM_ABI}

post-extract: enigmail-post-extract
.PHONY: enigmail-post-extract
enigmail-post-extract:
	${RUN} mv ${WRKDIR}/enigmail ${WRKSRC}/mailnews/extensions/
	${RUN} cd ${WRKSRC} && \
		${PATCH} < ${FILESDIR}/mailnews_extensions_enigmail_ipc_modules_subprocess.jsm
	${RUN} cd ${WRKSRC}/mailnews/extensions/enigmail && \
		${PATCH} -p1 < ${FILESDIR}/patch-ipc_src_Makefile

post-configure: enigmail-post-configure
.PHONY: enigmail-post-configure
enigmail-post-configure:
	${RUN} cd ${WRKSRC}/mailnews/extensions/enigmail &&		\
	  ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

# We need to do a switcheroo of the dist directory while building enigmail;
# otherwise we get extra files contamination in the PLIST.
post-build: enigmail-post-build
.PHONY: enigmail-post-build
enigmail-post-build:
	${RUN} cd ${WRKSRC}/${OBJDIR}/mozilla/dist && pax -rwpe . ../dist.save
	${RUN} cd ${WRKSRC}/mailnews/extensions/enigmail &&		\
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} &&			\
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} xpi
	${CP} ${WRKSRC}/mailnews/extensions/enigmail/build/enigmail*.xpi\
	  ${WRKDIR}/enigmail.xpi
#	${RUN} rm -rf ${WRKSRC}/mozilla/dist
#	${RUN} cd ${WRKSRC}/mozilla/dist.save && pax -rwpe . ../dist
