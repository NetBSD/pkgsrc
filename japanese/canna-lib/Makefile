# $NetBSD: Makefile,v 1.2 1999/08/27 04:06:57 sakamoto Exp $
#

DISTNAME=	Canna35b2
PKGNAME=	Canna-lib-3.5b2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/

PATCH_SITES=	http://www.jaist.ac.jp/~fujieda/canna/
PATCHFILES=	Canna35b2-unoff1.patch.gz Canna35b2-unoff2.patch.gz \
		Canna35b2-hack1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/

PLIST_TMP=	${PKGDIR}/PLIST
PLIST_SRC=	${WRKDIR}/PLIST

INSTALL_TARGET=	install install.man

.include "../../mk/bsd.prefs.mk"
CANNAOWNER?=    daemon
CANNAGROUP?=    daemon
DICT_DIR?=	/var/dict
MAKE_ENV+=      CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		DICT_DIR=${DICT_DIR}

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

do-configure:
	@(cd ${WRKSRC}; ${XMKMF})

post-configure:
	@${LN} -s ${WRKSRC}/server/*.h ${WRKSRC}/include

post-build:
	@${SED} -e 's|$${CANNAOWNER}|${CANNAOWNER}|'		\
		-e 's|$${CANNAGROUP}|${CANNAGROUP}|'		\
		-e 's|$${DICT_DIR}|${DICT_DIR}|'		\
		-e 's|$${PREFIX}|${PREFIX}|'			\
		${PLIST_TMP} > ${PLIST_SRC}

post-install:
	@${LN} -s ${DICT_DIR}/canna ${PREFIX}/share/canna/dic

.include "../../mk/bsd.pkg.mk"
