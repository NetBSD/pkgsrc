# $NetBSD: Makefile,v 1.7 2002/06/15 09:26:24 shell Exp $

DISTNAME=	vicq-0.4.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gonzo.kiev.ua/projects/vicq/
COMMENT=	simple icq client written in perl

WRKSRC=		${WRKDIR}/vicq

DEPEND+=	p5-Term-ReadLine>=1.11:../../devel/p5-Term-ReadLine

REPLACE_PERL=	${WRKSRC}/vicq
NO_BUILD=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/vICQ/.packlist

do-install:
	(cd ${WRKSRC}; perl ./install.pl --prefix=${PREFIX})
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
