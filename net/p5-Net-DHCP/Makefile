# $NetBSD: Makefile,v 1.12 2017/06/05 14:24:18 ryoon Exp $
#

DISTNAME=	Net-DHCP-0.696
PKGNAME=	p5-${DISTNAME:S/696/69.6/}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-DHCP/
COMMENT=	Object methods to create a DHCP packet
LICENSE=	${PERL5_LICENSE}

EGSUBDIR=       share/examples/p5-Net-DHCP
INSTALLATION_DIRS+=     ${EGSUBDIR}

EGFILES=	examples/dhcp_sniffer.pl
EGFILES+=	examples/dhcpd.pl
EGFILES+=	examples/dhcpd_test.pl
EGFILES+=	examples/dumpianatoxml.pl
EGFILES+=	examples/l2tp-dhcp-inform
EGFILES+=	examples/lease_query.pl
EGFILES+=	examples/list_dho.pl
EGFILES+=	examples/send_packet.pl

PERL5_REQD+=		5.8.0
PERL5_MODULE_TYPE=	Module::Build

REPLACE_PERL+=	${EGFILES}
# has /bin/false as shebang argument
CHECK_INTERPRETER_SKIP+=	${PERL5_SUB_INSTALLVENDORLIB}/Net/DHCP/Constants.pm
CHECK_INTERPRETER_SKIP+=	${PERL5_SUB_INSTALLVENDORLIB}/Net/DHCP/Packet.pm

post-install:
.for i in ${EGFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DESTDIR:Q}${PREFIX:Q}/${EGSUBDIR}
.endfor

PERL5_PACKLIST=		auto/Net/DHCP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
