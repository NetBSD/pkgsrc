# $NetBSD: Makefile,v 1.1.1.1 2002/01/31 07:34:51 martti Exp $
#

DISTNAME=	Net-AOLIM-1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	schmonz+netbsd@schmonz.com
HOMEPAGE=	http://www.phonon.net/pub/Net-AOLIM/
COMMENT=	perl5 module for connecting to AOL IM (TOC protocol)

WRKSRC=		${WRKDIR}/Net-AOLIM

USE_BUILDLINK_ONLY=     YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/AOLIM/.packlist

post-extract:
	${MV} ${WRKSRC}/example.pl ${WRKSRC}/AOLIM-example.pl
	${MV} ${WRKSRC}/MANIFEST ${WRKSRC}/MANIFEST.orig
	${SED} -e 's|^example\.pl|AOLIM-example.pl|' < ${WRKSRC}/MANIFEST.orig > ${WRKSRC}/MANIFEST

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
	${INSTALL_MAN} ${WRKSRC}/TOC.7 ${PREFIX}/man/man7

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
