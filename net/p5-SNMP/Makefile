# $NetBSD: Makefile,v 1.1 1998/05/24 12:33:45 hubertf Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/06/27 01:53:13 jfitz Exp
#

DISTNAME=	SNMP-1.7
PKGNAME=	p5-SNMP-1.7
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SNMP

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS= 	${PREFIX}/lib/libsnmp.a:${PKGSRCDIR}/net/ucd-snmp

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
		@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/lib/perl5/site_perl/README.SNMP

.include "../../mk/bsd.pkg.mk"
