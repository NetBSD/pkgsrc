# $NetBSD: Makefile,v 1.25 2018/02/26 12:32:41 triaxx Exp $

DISTNAME=	CSP-0.34
CATEGORIES=	security
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} cspguide.pdf
EXTRACT_ONLY=	${DISTFILES:N*.pdf}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple PKI Toolkit

DEPENDS+=	p5-Date-Calc>=5.4:../../devel/p5-Date-Calc
DEPENDS+=	p5-IPC-Run>=0.79:../../devel/p5-IPC-Run
DEPENDS+=	p5-Term-Prompt>=1.03:../../devel/p5-Term-Prompt

USE_TOOLS+=	pax
BUILD_DEFS+=	VARBASE
OWN_DIRS=	${VARBASE}/csp

INSTALLATION_DIRS=	 ${VARBASE}/csp share/doc/csp

SUBST_CLASSES+=		csp
SUBST_FILES.csp=	csp
SUBST_SED.csp=		-e s,@CSPHOME@,${VARBASE}/csp,
SUBST_SED.csp+=		-e s,@OPENSSL@,${BUILDLINK_PREFIX.openssl}/bin/openssl,
SUBST_STAGE.csp=	pre-install

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${CSPHOME}
	cd ${WRKSRC}/ca && ${FIND} . -type f | pax -rw ${DESTDIR}${VARBASE}/csp
	${INSTALL_DATA} ${DISTDIR}/cspguide.pdf ${DESTDIR}${PREFIX}/share/doc/csp

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
