# $NetBSD: Makefile,v 1.4 2020/09/07 13:08:31 wiz Exp $

DISTNAME=	Net-SFTP-Foreign-1.91
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://github.com/salva/p5-Net-SFTP-Foreign/
COMMENT=	SSH File Transfer Protocol client
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Net/SFTP/Foreign/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
