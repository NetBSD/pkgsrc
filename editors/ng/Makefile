# $NetBSD: Makefile,v 1.22 2008/03/03 18:25:53 jlam Exp $

DISTNAME=	ng-1.4.3
PKGREVISION=	1
CATEGORIES=	editors japanese
MASTER_SITES=	http://tt.sakura.ne.jp/~amura/archives/ng/

MAINTAINER=	fk200329@fsinet.or.jp
HOMEPAGE=	http://tt.sakura.ne.jp/~amura/ng/
COMMENT=	Very light Emacs-clone with japanese support

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ng

PKG_SUPPORTED_OPTIONS=	canna
PKG_SUGGESTED_OPTIONS=	canna
PKG_OPTIONS_VAR=	PKG_OPTIONS.ng

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcanna)
.include "../../inputmethod/canna-lib/buildlink3.mk"
MAKEFLAGS+=	USE_CANNA=YES
.endif

BUILD_TARGET=	ng

INSTALLATION_DIRS=	bin

post-patch:
	@(cd ${WRKSRC}; ${LN} -s sys/bsd/Makefile . )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ng
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.FAQ ${DESTDIR}${PREFIX}/share/doc/ng/Ng.FAQ.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.doc ${DESTDIR}${PREFIX}/share/doc/ng/Ng.doc.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.ref ${DESTDIR}${PREFIX}/share/doc/ng/Ng.ref.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.tut ${DESTDIR}${PREFIX}/share/doc/ng/Ng.tut.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.Ng ${DESTDIR}${PREFIX}/share/doc/ng/README.Ng.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.SKG ${DESTDIR}${PREFIX}/share/doc/ng/README.SKG.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.new ${DESTDIR}${PREFIX}/share/doc/ng/CHANGES.new.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.doc ${DESTDIR}${PREFIX}/share/doc/ng/CHANGES.doc.euc-jp

.include "../../mk/bsd.pkg.mk"
