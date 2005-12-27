# $NetBSD: Makefile,v 1.1.1.1 2005/12/27 20:56:17 cube Exp $
#

DISTNAME=	CSP-0.32
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.su.se/pub/users/leifj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CSPGUIDE}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://devel.it.su.se/pub/jsp/polopoly.jsp?d=1026&a=3290
COMMENT=	Simple PKI Toolkit

DEPENDS+=	p5-Date-Calc>=5.4:../../devel/p5-Date-Calc
DEPENDS+=	p5-IPC-Run>=0.79:../../devel/p5-IPC-Run
DEPENDS+=	p5-Term-Prompt>=1.03:../../devel/p5-Term-Prompt

CSPGUIDE=	cspguide.pdf
SITES_${CSPGUIDE}=	http://devel.it.su.se/content/1/c4/32/90/
EXTRACT_ONLY=	${DISTFILES:N*.pdf}

PERL5_PACKLIST=	auto/CSP/.packlist

CSPHOME=	${VARBASE}/csp
OPENSSLBIN=	${BUILDLINK_PREFIX.openssl}/bin/openssl
OWN_DIRS=	${CSPHOME}
INSTALLATION_DIRS=	share/doc/csp

BUILD_DEFS+=	CSPHOME

SUBST_CLASSES+=		csp
SUBST_FILES.csp=	csp
SUBST_SED.csp=		-e s,@@CSPHOME@@,${CSPHOME},	\
			-e s,@@OPENSSL@@,${OPENSSLBIN},
SUBST_STAGE.csp=	post-patch

post-install:
	cd ${WRKSRC}/ca && ${FIND} . -type f | ${PAX} -rw ${CSPHOME}
	${INSTALL_DATA} ${DISTDIR}/${CSPGUIDE} ${PREFIX}/share/doc/csp

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
