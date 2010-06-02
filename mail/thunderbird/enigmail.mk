# $NetBSD: enigmail.mk,v 1.1 2010/06/02 15:39:26 tnn Exp $
#
# This Makefile fragment hooks the Enigmail OpenPGP extension
# (see http://www.mozilla-enigmail.org/ ) into the build.

ENIGMAIL_DIST=		enigmail-1.0.1.tar.gz
ENIGMAIL_UUID=		847b3a00-7ab1-11d4-8f02-006008948af5
.if !defined(DISTFILES)
DISTFILES=		${DEFAULT_DISTFILES}
.endif
DISTFILES+=		${ENIGMAIL_DIST}
SITES.${ENIGMAIL_DIST}=	http://www.mozilla-enigmail.org/download/source/

DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
PLIST_SRC+=		PLIST.enigmail
USE_TOOLS+=		unzip pax

post-extract: enigmail-post-extract
.PHONY: enigmail-post-extract
enigmail-post-extract:
	${RUN} mv ${WRKDIR}/enigmail ${WRKSRC}/mailnews/extensions/

post-configure: enigmail-post-configure
.PHONY: enigmail-post-configure
enigmail-post-configure:
	${RUN} cd ${WRKSRC}/mailnews/extensions/enigmail &&		\
	  ${SETENV} ${CONFIGURE_ENV} ${PERL5} ./makemake -r

# We need to do a switcheroo of the dist directory while building enigmail;
# otherwise we get extra files contamination in the PLIST.
post-build: enigmail-post-build
.PHONY: enigmail-post-build
enigmail-post-build:
	${RUN} cd ${WRKSRC}/mozilla/dist && pax -rwpe . ../dist.save
	${RUN} cd ${WRKSRC}/mailnews/extensions/enigmail &&		\
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} &&			\
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} xpi
	${RUN} ${MKDIR} "${WRKDIR}/{${ENIGMAIL_UUID}}"
	${RUN} cd "${WRKDIR}/{${ENIGMAIL_UUID}}" &&			\
	  ${UNZIP_CMD} -aqo ${WRKSRC}/mozilla/dist/bin/enigmail*.xpi
	${RUN} rm -rf ${WRKSRC}/mozilla/dist
	${RUN} cd ${WRKSRC}/mozilla/dist.save && pax -rwpe . ../dist

post-install: enigmail-post-install
.PHONY: enigmail-post-install
enigmail-post-install:
	${RUN} cd ${WRKDIR} && pax -rw "{${ENIGMAIL_UUID}}"		\
	  ${DESTDIR}${PREFIX}/lib/${MOZILLA}/extensions/.
