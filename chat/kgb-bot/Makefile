# $NetBSD: Makefile,v 1.13 2022/06/28 11:31:03 wiz Exp $
#

DISTNAME=	App-KGB-1.31
PKGNAME=	${DISTNAME:S/App-KGB/kgb-bot/}
PKGREVISION=	10

CATEGORIES=	chat perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://alioth.debian.org/projects/kgb/
COMMENT=	Notify about VCS commits on IRC

USE_TOOLS+=	perl:run

DEPENDS+=		p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=		p5-File-Touch-[0-9]*:../../devel/p5-File-Touch
DEPENDS+=		p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
DEPENDS+=		p5-JSON-RPC-[0-9]*:../../www/p5-JSON-RPC
DEPENDS+=		p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=		p5-POE-[0-9]*:../../devel/p5-POE
DEPENDS+=		p5-POE-Component-IRC-[0-9]*:../../chat/p5-POE-Component-IRC
DEPENDS+=		p5-POE-Component-Server-SOAP-[0-9]*:../../www/p5-POE-Component-Server-SOAP
DEPENDS+=		p5-Proc-PID-File-[0-9]*:../../devel/p5-Proc-PID-File
DEPENDS+=		p5-Schedule-RateLimiter-[0-9]*:../../devel/p5-Schedule-RateLimiter
DEPENDS+=		p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=		p5-subversion-[0-9]*:../../devel/p5-subversion
DEPENDS+=		p5-WWW-Shorten-[0-9]*:../../www/p5-WWW-Shorten
DEPENDS+=		p5-YAML-[0-9]*:../../textproc/p5-YAML

RCD_SCRIPTS=		kgb_bot
RCD_SCRIPT_SRC.kgb_bot=	files/kgb_bot.sh

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	/usr/bin/perl
REPLACE.perl.new=	${TOOLS_PATH.perl}
REPLACE_FILES.perl=	script/kgb-add-project script/kgb-bot
REPLACE_FILES.perl+=	script/kgb-split-config script/kgb-client
REPLACE_FILES.perl+=	eg/simple-soap-client eg/simple-soap-server

SUBST_CLASSES+=		configs
SUBST_STAGE.configs=	pre-configure
SUBST_FILES.configs=	script/kgb-add-project script/kgb-bot
SUBST_FILES.configs+=	script/kgb-split-config
SUBST_SED.configs=	-e "s,/etc/,${PKG_SYSCONFDIR}/,g"

MAKE_ENV+=		PERL=${TOOLS_PATH.perl}

PERL5_PACKLIST=		auto/App/KGB/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
