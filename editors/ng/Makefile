# $NetBSD: Makefile,v 1.1.1.1 2000/10/19 23:54:37 hubertf Exp $

DISTNAME=	ng-1.4
CATEGORIES=     editors japanese
MASTER_SITES=   http://ha3.seikyou.ne.jp/home/amura/archives/ng/

MAINTAINER=     fk200329@fsinet.or.jp
HOMEPAGE=	http://ha3.seikyou.ne.jp/home/amura/ng/


.include "../../mk/bsd.prefs.mk"	# for USE_CANNA

.if !defined(USE_CANNA)
USE_CANNA=	YES
.endif

.if ${USE_CANNA} == "YES"
DEPENDS=	Canna-lib-3.5b2:../../japanese/canna-lib
.endif

WRKSRC=         ${WRKDIR}/ng
ALL_TARGET=	ng
MAKEFLAGS+=	USE_CANNA=${USE_CANNA}

post-patch:
.if ${USE_CANNA} != "YES"
	@(cd ${WRKSRC}; ${MV} config.h config.h.orig )
	@(cd ${WRKSRC};	${SED} -e "s/#define CANNA/#undef CANNA/" config.h.orig > config.h )
.endif
	@(cd ${WRKSRC}; ${LN} -s sys/bsd/Makefile . )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin/

post-install:
	${MKDIR} ${PREFIX}/share/doc/ng
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.FAQ ${PREFIX}/share/doc/ng/Ng.FAQ.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.doc ${PREFIX}/share/doc/ng/Ng.doc.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.ref ${PREFIX}/share/doc/ng/Ng.ref.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.tut ${PREFIX}/share/doc/ng/Ng.tut.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.Ng ${PREFIX}/share/doc/ng/README.Ng.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.SKG ${PREFIX}/share/doc/ng/README.SKG.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.new ${PREFIX}/share/doc/ng/CHANGES.new.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.doc ${PREFIX}/share/doc/ng/CHANGES.doc.euc-jp

.include "../../mk/bsd.pkg.mk"
