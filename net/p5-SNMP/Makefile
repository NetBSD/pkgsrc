# $NetBSD: Makefile,v 1.6 2000/08/27 07:11:17 jlam Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/06/27 01:53:13 jfitz Exp
#

DISTNAME=	SNMP-1.7
PKGNAME=	p5-SNMP-1.7
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	packages@netbsd.org

DEPENDS=	ucd-snmp>=4.0.1:../../net/ucd-snmp

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/SNMP/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
	@${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/lib/perl5/site_perl/README.SNMP

.include "../../mk/bsd.pkg.mk"
