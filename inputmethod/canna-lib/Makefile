# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 18:47:16 jlam Exp $
#

DISTNAME=	Canna35b2
PKGNAME=	Canna-lib-3.5.2
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/

PATCH_SITES=	http://www.jaist.ac.jp/~fujieda/canna/
PATCHFILES=	Canna35b2-unoff1.patch.gz Canna35b2-unoff2.patch.gz \
		Canna35b2-hack1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/
COMMENT=	Kana-Kanji conversion system (library)

INSTALL_TARGET=	install install.man

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"
.if 0	# ${USE_INET6} == "YES"
INET6=		-DINET6
.else
INET6=		# empty
.endif
CANNAOWNER?=    daemon
CANNAGROUP?=    daemon
MAKE_ENV+=      CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		INET6=${INET6}

# (1) Change SUBDIRS.
# (2) Don't install `forcpp', `kpdic'.
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

# We need to pass ${MAKE_ENV} to ${XMKMF}
do-configure:
	@cd ${WRKSRC} && \
	    ${SETENV} ${SCRIPTS_ENV} ${MAKE_ENV} ${XMKMF}

post-configure:
	@${LN} -s ${WRKSRC}/server/*.h ${WRKSRC}/include

.include "../../devel/nbitools/nbitools.mk"
.include "../../mk/bsd.pkg.mk"
