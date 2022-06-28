# $NetBSD: Makefile,v 1.37 2022/06/28 11:35:13 wiz Exp $
#

DISTNAME=	Net-Pcap-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Pcap
COMMENT=	Perl interface to pcap(3) LBL packet capture library
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Interface-[0-9]*:../../net/p5-IO-Interface
# Used during test, doesn't work properly:
# BUILD_DEPENDS+= p5-Test-Distribution-[0-9]*:../../devel/p5-Test-Distribution

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.5

PERL5_PACKLIST=	auto/Net/Pcap/.packlist

MAKE_PARAMS+=	INC=-I${BUILDLINK_PREFIX.libpcap}/include
MAKE_PARAMS+=	LIBS='-L${BUILDLINK_PREFIX.libpcap}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libpcap}/lib -lpcap'

SUBST_CLASSES+=		pcaplib
SUBST_STAGE.pcaplib=	pre-configure
SUBST_FILES.pcaplib=	Makefile.PL
SUBST_SED.pcaplib=	-e 's,@PCAP_LIBDIR@,${BUILDLINK_PREFIX.libpcap}/lib,'

.include "../../lang/perl5/module.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
