# $NetBSD: Makefile,v 1.16 2004/05/31 16:47:47 minskim Exp $

DISTNAME=	vicq-0.4.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gonzo.kiev.ua/projects/vicq/
COMMENT=	Simple icq client written in perl

DEPENDS+=	p5-Term-ReadLine>=1.11:../../devel/p5-Term-ReadLine

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/vicq
USE_BUILDLINK3=		YES
NO_BUILD=		YES

REPLACE_PERL=		vicq
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/vICQ/.packlist

INSTALLATION_DIRS=	bin man

do-install:
	(cd ${WRKSRC}; ${PERL5} ./install.pl --prefix=${PREFIX})
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
