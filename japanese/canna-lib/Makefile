# $NetBSD: Makefile,v 1.11 2002/04/05 12:40:00 hubertf Exp $
#

DISTNAME=	Canna35b2
PKGNAME=	Canna-lib-3.5b2
PKGREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/

PATCH_SITES=	http://www.jaist.ac.jp/~fujieda/canna/
PATCHFILES=	Canna35b2-unoff1.patch.gz Canna35b2-unoff2.patch.gz \
		Canna35b2-hack1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/
COMMENT=	Kana-Kanji conversion system (library)

INSTALL_TARGET=	install install.man

# XXX USE_IMAKE can't pass MAKE_FLAGS to XMKMF.
#USE_IMAKE=	# defined
BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"
.if 0	# ${USE_INET6} == "YES"
INET6=		-DINET6
.else
INET6=		# empty
.endif
CANNAOWNER?=    daemon
CANNAGROUP?=    daemon
DICT_DIR?=	${DESTDIR}/var/dict
MAKE_ENV+=      CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		DICT_DIR=${DICT_DIR} INET6=${INET6}
PLIST_SUBST=	CANNAOWNER=${CANNAOWNER}	\
		CANNAGROUP=${CANNAGROUP}	\
		DICT_DIR=${DICT_DIR}		\
		PREFIX=${PREFIX}

# (1) Change SUBDIRS.
# (2) Don't install `forcpp', `kpdic'.
# (3) Include ${FILESDIR}/LinkFileList.rules just after including Canna.conf
#     in Imakefiles.
post-patch:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED}	-e 's|\(SUBDIRS = lib canna\).*\( misc\)|\1 cmd/forcpp cmd/kpdic dic/phono\2|' \
		-e 's|\(SGSDIR = \).*|\1 lib canna dic/phono misc doc|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
.for f in forcpp kpdic
	@${MV} ${WRKSRC}/cmd/${f}/Imakefile ${WRKSRC}/cmd/${f}/Imakefile.orig
	@${SED} -e '/InstallProgram/d' ${WRKSRC}/cmd/${f}/Imakefile.orig \
		> ${WRKSRC}/cmd/${f}/Imakefile
.endfor
	@${FIND} ${WRKSRC} -name Imakefile -print | \
	while read f; do \
		${CP} $$f $${f}.orig; \
		( \
			${ECHO} '/#include ".*\/Canna.conf"$$/a\'; \
			${ECHO} '#include "${FILESDIR}/LinkFileList.rules"'; \
		) | ${SED} -f /dev/stdin $${f}.orig >$$f; \
	done

# We need to pass ${MAKE_ENV} to ${XMKMF}
do-configure:
	@cd ${WRKSRC} && \
	    ${SETENV} ${SCRIPTS_ENV} XPROJECTROOT=${X11BASE} ${MAKE_ENV} ${XMKMF}

post-configure:
	@${LN} -s ${WRKSRC}/server/*.h ${WRKSRC}/include

post-install:
	@${LN} -s ${DICT_DIR}/canna ${PREFIX}/share/canna/dic
	@${CHOWN} ${CANNAOWNER}:${CANNAGROUP} ${DICT_DIR}/canna

.include "../../mk/bsd.pkg.mk"
