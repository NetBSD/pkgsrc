# $NetBSD: Makefile,v 1.18 2022/06/28 11:34:59 wiz Exp $

DISTNAME=	dotse-dnscheck-1.5.4-0-g352a15c
PKGNAME=	dnscheck-1.5.4
PKGREVISION=	9
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=dotse/dnscheck/tarball/1.5.4/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/dotse/dnscheck/
COMMENT=	DNSCheck is a DNS quality checker
LICENSE=	2-clause-bsd

# If you're not able to download the distfile, try using
#FETCH_USING=	curl # in mk.conf or on the command-line

DEPENDS+=	p5-Net-DNS>=0.65:../../net/p5-Net-DNS
DEPENDS+=	p5-Net-DNS-SEC>=0.16:../../security/p5-Net-DNS-SEC
DEPENDS+=	p5-Net-IP>=1.25:../../net/p5-Net-IP
DEPENDS+=	p5-TimeDate>=0.19:../../time/p5-TimeDate
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-Socket6>=0.19:../../net/p5-Socket6
DEPENDS+=	p5-IO-Socket-INET6>=2.51:../../net/p5-IO-Socket-INET6
DEPENDS+=	p5-Mail-RFC822-Address-[0-9]*:../../mail/p5-Mail-RFC822-Address
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Config-Any-[0-9]*:../../devel/p5-Config-Any
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-MIME-Lite-[0-9]*:../../mail/p5-MIME-Lite
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils

REPLACE_PERL+=	lib/DNSCheck.pm lib/DNSCheck/*.pm
REPLACE_PERL+=	lib/DNSCheck/Lookup/*.pm lib/DNSCheck/Test/*.pm
REPLACE_PERL+=	apps/dnscheck-enqueue apps/dnscheck-packetcheck

PERL5_PACKLIST=			auto/DNSCheck/.packlist

BUILD_DEFS+=	IPV6_READY

INSTALLATION_DIRS=	${EGDIR}
OWN_DIRS=		${SYSCONFDIR}/${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	lib/DNSCheck/Config.pm
SUBST_SED.paths+=	-e s!/etc!${SYSCONFDIR}!g

WRKSRC=		${WRKDIR}/dotse-dnscheck-006ca8d/engine
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

post-install:
	${CP} -r ${WRKSRC}/config ${DESTDIR}${EGDIR}/

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
