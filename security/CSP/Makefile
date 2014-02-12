# $NetBSD: Makefile,v 1.17 2014/02/12 23:18:30 tron Exp $
#

DISTNAME=	CSP-0.32
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.su.se/pub/users/leifj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CSPGUIDE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://devel.it.su.se/pub/jsp/polopoly.jsp?d=1026&a=3290
COMMENT=	Simple PKI Toolkit

DEPENDS+=	p5-Date-Calc>=5.4:../../devel/p5-Date-Calc
DEPENDS+=	p5-IPC-Run>=0.79:../../devel/p5-IPC-Run
DEPENDS+=	p5-Term-Prompt>=1.03:../../devel/p5-Term-Prompt

USE_TOOLS+=	pax

CSPGUIDE=	cspguide.pdf
SITES.${CSPGUIDE}=	http://devel.it.su.se/content/1/c4/32/90/
EXTRACT_ONLY=	${DISTFILES:N*.pdf}

PERL5_PACKLIST=	auto/CSP/.packlist

CSPHOME=	${VARBASE}/csp
OPENSSLBIN=	${BUILDLINK_PREFIX.openssl}/bin/openssl
OWN_DIRS=	${CSPHOME}
INSTALLATION_DIRS=	share/doc/csp ${CSPHOME}

BUILD_DEFS+=	CSPHOME

SUBST_CLASSES+=		csp
SUBST_FILES.csp=	csp
SUBST_SED.csp=		-e s,@@CSPHOME@@,${CSPHOME},
SUBST_SED.csp+=		-e s,@@OPENSSL@@,${OPENSSLBIN},
SUBST_STAGE.csp=	post-patch

post-install:
	cd ${WRKSRC}/ca && ${FIND} . -type f | pax -rw ${DESTDIR}${CSPHOME}
	${INSTALL_DATA} ${DISTDIR}/${CSPGUIDE} ${DESTDIR}${PREFIX}/share/doc/csp

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
