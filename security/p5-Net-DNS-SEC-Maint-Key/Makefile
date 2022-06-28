# $NetBSD: Makefile,v 1.22 2022/06/28 11:35:48 wiz Exp $
#

DISTNAME=		Net-DNS-SEC-Maint-Key-0.013
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		security net perl5
#MASTER_SITES=		https://www.ripe.net/disi/dnssec_maint_tool/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://www.ripe.net/disi/dnssec_maint_tool/
COMMENT=		DNSSEC key and key-set maintenance classes and tool

DEPENDS+=		p5-Net-DNS>=0.44:../../net/p5-Net-DNS
DEPENDS+=		p5-Net-DNS-SEC>=0.12:../../security/p5-Net-DNS-SEC
DEPENDS+=		p5-IO-LockedFile-[0-9]*:../../devel/p5-IO-LockedFile
DEPENDS+=		p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
#DEPENDS+=		{perl>=5.17.10,p5-Term-ReadLine>=1.12}:../../devel/p5-Term-ReadLine

PERL5_PACKLIST=		auto/Net/DNS/SEC/Maint/Key/.packlist

REPLACE_PERL=		apps/dnssecmaint-config
REPLACE_PERL+=		apps/dnssecmaint-copyprivate
REPLACE_PERL+=		apps/maintkeydb

INSTALLATION_DIRS=	bin

post-install:
	for s in dnssecmaint-config dnssecmaint-copyprivate maintkeydb; do \
		${INSTALL_SCRIPT} ${WRKSRC}/blib/script/$$s \
			${DESTDIR}/${PREFIX}/bin; \
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
