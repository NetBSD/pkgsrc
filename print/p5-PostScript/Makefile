# $NetBSD: Makefile,v 1.13 2024/01/16 22:55:36 rillig Exp $

DISTNAME=	PostScript-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PostScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PostScript
COMMENT=	Produce PostScript files from Perl
LICENSE=	${PERL5_LICENSE}

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	post-install
SUBST_FILES.destdir=	${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORARCH}/auto/PostScript/Metrics/.packlist
SUBST_SED.destdir=	-e 's|^${DESTDIR}${PREFIX}|${PREFIX}|'

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
