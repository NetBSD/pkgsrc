# $NetBSD: Makefile,v 1.8 2001/01/30 22:03:38 wrstuden Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/06/27 01:53:13 jfitz Exp
#

DISTNAME=	SNMP-3.1.0
PKGNAME=	p5-SNMP-3.1.0
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	packages@netbsd.org

DEPENDS=	ucd-snmp>=4.1.0:../../net/ucd-snmp

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/SNMP/.packlist

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
#MAKE_PARAMS=	DEFINE="-DPERL_POLLUTE=1"

PLFILES=	async1.pl async2.pl ipforward.pl mibtree.pl mibwalk.pl
PLFILES+=	pingmib.pl tablewalk.pl testleak.pl

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

post-build:
	@for i in ${PLFILES} ; do ${ECHO} "#! ${PREFIX}/bin/perl" | ${CAT} - ${WRKSRC}/examples/$$i > ${WRKDIR}/$$i ; done

post-install:
	@${INSTALL_DATA} ${WRKSRC}/README ${PERL5_SITELIB}/README.SNMP
	@${MKDIR} ${PREFIX}/share/examples/p5-SNMP
	@for i in ${PLFILES} ; do ${INSTALL_SCRIPT} ${WRKDIR}/$$i ${PREFIX}/share/examples/p5-SNMP/$$i ; done

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
