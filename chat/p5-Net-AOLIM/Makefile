# $NetBSD: Makefile,v 1.13 2006/10/02 21:27:03 rillig Exp $
#

DISTNAME=	Net-AOLIM-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.phonon.net/pub/Net-AOLIM/
COMMENT=	Perl5 module for connecting to AOL IM (TOC protocol)

WRKSRC=		${WRKDIR}/Net-AOLIM
PERL5_PACKLIST=	auto/Net/AOLIM/.packlist
REPLACE_PERL+=	AOLIM-example.pl

INSTALLATION_DIRS=	${PKGMANDIR}/man7

pre-configure:
	${MV} ${WRKSRC}/example.pl ${WRKSRC}/AOLIM-example.pl; \
	${MV} ${WRKSRC}/MANIFEST ${WRKSRC}/MANIFEST.orig && \
	${SED} -e 's|^example\.pl|AOLIM-example.pl|' \
		< ${WRKSRC}/MANIFEST.orig > ${WRKSRC}/MANIFEST

post-install:
	${INSTALL_MAN} ${WRKSRC}/TOC.7 ${PREFIX}/${PKGMANDIR}/man7

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
