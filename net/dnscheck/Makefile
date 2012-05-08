# $NetBSD: Makefile,v 1.1.1.1 2012/05/08 22:39:39 pettai Exp $
#

DISTNAME=	dotse-dnscheck-1.2.6-0-g86a5c69
PKGNAME=	dnscheck-1.2.6
CATEGORIES=	net perl5
MASTER_SITES=	-https://github.com/dotse/dnscheck/tarball/1.2.6

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/dotse/dnscheck/
COMMENT=	DNSCheck is a DNS quality checker
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

FETCH_USING=	curl

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
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-MIME-Lite-[0-9]*:../../mail/p5-MIME-Lite
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template

REPLACE_PERL+=  lib/DNSCheck.pm lib/DNSCheck/*.pm
REPLACE_PERL+=  lib/DNSCheck/Lookup/*.pm lib/DNSCheck/Test/*.pm

PERL5_PACKLIST=	auto/DNSCheck/.packlist
BUILDLINK_API_DEPENDS.perl+=	perl>=5.6.1

WRKSRC=         ${WRKDIR}/dotse-dnscheck-b73204b/engine
SYSCONFDIR=     `${BASENAME} ${PKG_SYSCONFDIR}`

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/config.yaml ${PKG_SYSCONFDIR}/${PKGBASE}/config.yaml
CONF_FILES+=	${EGDIR}/policy.yaml ${PKG_SYSCONFDIR}/${PKGBASE}/policy.yaml

BUILD_DEFS+=    IPV6_READY

SUBST_CLASSES+=         paths
SUBST_STAGE.paths=      pre-configure
SUBST_FILES.paths=      lib/DNSCheck/Config.pm
SUBST_SED.paths+=       -e s!@SYSCONFDIR@!${SYSCONFDIR}!g

INSTALLATION_DIRS=	${EGDIR}
OWN_DIRS=		${SYSCONFDIR}/${PKGBASE}

post-patch:
	${RM} ${WRKSRC}/lib/DNSCheck/Config.pm.orig

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.yaml ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/policy.yaml ${DESTDIR}${EGDIR}/

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
