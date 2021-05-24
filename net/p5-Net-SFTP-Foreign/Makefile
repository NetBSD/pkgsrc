# $NetBSD: Makefile,v 1.5 2021/05/24 19:53:30 wiz Exp $

DISTNAME=	Net-SFTP-Foreign-1.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://github.com/salva/p5-Net-SFTP-Foreign/
COMMENT=	SSH File Transfer Protocol client
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Net/SFTP/Foreign/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
