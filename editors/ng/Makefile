# $NetBSD: Makefile,v 1.26 2012/12/12 12:04:51 wiz Exp $

DISTNAME=	ng-1.4.4
CATEGORIES=	editors japanese
MASTER_SITES=	http://tt.sakura.ne.jp/~amura/archives/ng/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ng-1.4.4-replace_bug.patch

MAINTAINER=	fk200329@fsinet.or.jp
HOMEPAGE=	http://tt.sakura.ne.jp/~amura/ng/
COMMENT=	Very light Emacs-clone with japanese support
#LICENSE=	GNU EMACS GENERAL PUBLIC LICENSE

PKG_SUPPORTED_OPTIONS=	canna
PKG_SUGGESTED_OPTIONS=	canna
PKG_OPTIONS_VAR=	PKG_OPTIONS.ng

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcanna)
.include "../../inputmethod/canna-lib/buildlink3.mk"
MAKEFLAGS+=	USE_CANNA=YES
.else
MAKEFLAGS+=	USE_CANNA=NO
.endif

BUILD_TARGET=	ng

INSTALLATION_DIRS=	bin share/doc/ng share/examples/ng

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
post-patch:
	cd ${WRKSRC}; ${LN} -s sys/sysv/Makefile .
.else
post-patch:
	cd ${WRKSRC}; ${LN} -s sys/bsd/Makefile .
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dot.ng ${DESTDIR}${PREFIX}/share/examples/ng/dot.ng.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.FAQ ${DESTDIR}${PREFIX}/share/doc/ng/Ng.FAQ.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.doc ${DESTDIR}${PREFIX}/share/doc/ng/Ng.doc.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.ref ${DESTDIR}${PREFIX}/share/doc/ng/Ng.ref.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.tut ${DESTDIR}${PREFIX}/share/doc/ng/Ng.tut.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.Ng ${DESTDIR}${PREFIX}/share/doc/ng/README.Ng.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.SKG ${DESTDIR}${PREFIX}/share/doc/ng/README.SKG.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.1_3 ${DESTDIR}${PREFIX}/share/doc/ng/CHANGES.1_3.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.doc ${DESTDIR}${PREFIX}/share/doc/ng/CHANGES.doc.euc-jp

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
