# $NetBSD: Makefile,v 1.13 2003/07/21 16:34:34 martti Exp $

DISTNAME=	vicq-0.4.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/vicq
CATEGORIES=	chat
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gonzo.kiev.ua/projects/vicq/
COMMENT=	Simple icq client written in perl

DEPEND+=	p5-Term-ReadLine>=1.11:../../devel/p5-Term-ReadLine

USE_BUILDLINK2=		YES
NO_BUILD=		YES

REPLACE_PERL=		vicq
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/vICQ/.packlist

do-install:
	(cd ${WRKSRC}; ${PERL5} ./install.pl --prefix=${PREFIX})
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
