# $NetBSD: Makefile,v 1.7 2000/08/29 20:48:14 jlam Exp $
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

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
MAKE_PARAMS=	DEFINE="-DPERL_POLLUTE=1"

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/README ${PERL5_SITELIB}/README.SNMP

.include "../../mk/bsd.pkg.mk"
