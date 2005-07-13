# $NetBSD: Makefile,v 1.11 2005/07/13 18:01:19 jlam Exp $
#

DISTNAME=	Net-AOLIM-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.phonon.net/pub/Net-AOLIM/
COMMENT=	Perl5 module for connecting to AOL IM (TOC protocol)

WRKSRC=		${WRKDIR}/Net-AOLIM
PERL5_PACKLIST=	auto/Net/AOLIM/.packlist

pre-configure:
	${MV} ${WRKSRC}/example.pl ${WRKSRC}/AOLIM-example.pl; \
	${MV} ${WRKSRC}/MANIFEST ${WRKSRC}/MANIFEST.orig && \
	${SED} -e 's|^example\.pl|AOLIM-example.pl|' \
		< ${WRKSRC}/MANIFEST.orig > ${WRKSRC}/MANIFEST

post-install:
	${INSTALL_MAN} ${WRKSRC}/TOC.7 ${PREFIX}/man/man7

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
