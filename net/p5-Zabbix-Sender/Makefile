# $NetBSD: Makefile,v 1.4 2017/06/05 14:24:25 ryoon Exp $
#

DISTNAME=	Zabbix-Sender-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Zabbix/}
CATEGORIES=	net perl5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pure-perl implementation of zabbix-sender
LICENSE=	artistic OR gnu-gpl-v1

DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON
DEPENDS+=	p5-Net>=0:../../net/p5-Net
DEPENDS+=	p5-namespace-autoclean>=0:../../devel/p5-namespace-autoclean

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Zabbix/Sender/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
