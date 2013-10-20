# $NetBSD: Makefile,v 1.1.1.1 2013/10/20 14:16:16 tonnerre Exp $
#

PKGNAME=	kgb-bot-1.31
DISTNAME=	${PKGNAME:S/kgb-bot/App-KGB/}

CATEGORIES=	chat perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	https://alioth.debian.org/projects/kgb/
COMMENT=	Notify about VCS commits on IRC

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_TOOLS+=	perl:run

DEPENDS+=		p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=		p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=		p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=		p5-subversion-[0-9]*:../../devel/p5-subversion
DEPENDS+=		p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=		p5-File-Touch-[0-9]*:../../devel/p5-File-Touch
DEPENDS+=		p5-WWW-Shorten-[0-9]*:../../www/p5-WWW-Shorten
DEPENDS+=		p5-JSON-RPC-[0-9]*:../../www/p5-JSON-RPC

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	/usr/bin/perl
REPLACE.perl.new=	${TOOLS_PATH.perl}
REPLACE_FILES.perl=	script/kgb-add-project script/kgb-bot
REPLACE_FILES.perl+=	script/kgb-split-config script/kgb-client
REPLACE_FILES.perl+=	eg/simple-soap-client eg/simple-soap-server

MAKE_ENV+=		PERL=${TOOLS_PATH.perl}

PERL5_PACKLIST=		auto/App/KGB/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
