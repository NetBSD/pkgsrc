# $NetBSD: Makefile,v 1.9 2002/04/14 15:10:04 jlam Exp $

DISTNAME=	ng-1.4.3
CATEGORIES=     editors japanese
MASTER_SITES=   http://tt.sakura.ne.jp/~amura/archives/ng/

MAINTAINER=     fk200329@fsinet.or.jp
HOMEPAGE=	http://tt.sakura.ne.jp/~amura/ng/
COMMENT=	Very light Emacs-clone with japanese support

.include "../../mk/bsd.prefs.mk"	# for USE_CANNA

.if !defined(USE_CANNA)
USE_CANNA=	YES
.endif

.if ${USE_CANNA} == "YES"
DEPENDS=	Canna-lib>=3.5.2:../../japanese/canna-lib
USE_X11=	YES
.endif

WRKSRC=         ${WRKDIR}/ng
ALL_TARGET=	ng
MAKEFLAGS+=	USE_CANNA=${USE_CANNA}

post-patch:
	@(cd ${WRKSRC}; ${LN} -s sys/bsd/Makefile . )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin/

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ng
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.FAQ ${PREFIX}/share/doc/ng/Ng.FAQ.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.doc ${PREFIX}/share/doc/ng/Ng.doc.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.ref ${PREFIX}/share/doc/ng/Ng.ref.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.tut ${PREFIX}/share/doc/ng/Ng.tut.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.Ng ${PREFIX}/share/doc/ng/README.Ng.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.SKG ${PREFIX}/share/doc/ng/README.SKG.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.new ${PREFIX}/share/doc/ng/CHANGES.new.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.doc ${PREFIX}/share/doc/ng/CHANGES.doc.euc-jp

.include "../../mk/bsd.pkg.mk"
