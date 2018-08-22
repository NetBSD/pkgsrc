# $NetBSD: Makefile,v 1.16 2018/08/22 09:45:28 wiz Exp $

DISTNAME=	Email-Folder-0.860
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Folder/
COMMENT=	Perl 5 module to read all the messages from a folder
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/Email/Folder/.packlist

DEPENDS+=	p5-Email-FolderType>=0.6:../../mail/p5-Email-FolderType
DEPENDS+=	p5-Email-Simple-[0-9]*:../../mail/p5-Email-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
