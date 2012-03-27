# $NetBSD: Makefile,v 1.1.1.1 2012/03/27 20:09:44 wiz Exp $
#

DISTNAME=	Net-DHCP-0.67
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-DHCP/
COMMENT=	Object methods to create a DHCP packet
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

EGSUBDIR=       share/examples/p5-Net-DHCP
INSTALLATION_DIRS+=     ${EGSUBDIR}

EGFILES=	examples/dhcp_sniffer.pl examples/dhcpd.pl examples/dhcpd_test.pl
EGFILES+=	examples/lease_query.pl examples/send_packet.pl

REPLACE_PERL+=	${EGFILES}

post-install:
.for i in ${EGFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DESTDIR:Q}${PREFIX:Q}/${EGSUBDIR}
.endfor

PERL5_PACKLIST=		auto/Net/DHCP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
