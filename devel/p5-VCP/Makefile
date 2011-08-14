# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:48 obache Exp $

DISTNAME=	VCP-autrijus-snapshot-0.9-${SNAPSHOT_VERS}
SNAPSHOT_VERS=	20050110
PKGNAME=	p5-${DISTNAME:S/-autrijus-snapshot-/-/:S/-${SNAPSHOT_VERS}$/beta${SNAPSHOT_VERS}/}
PKGREVISION=	3
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/A/AU/AUTRIJUS

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Versioned Copy, copying hierarchies of versioned files

BROKEN=		Fails to locate VCP/DiffFormat.pm

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Regexp-Shellish>=0.93:../../devel/p5-Regexp-Shellish
DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff
DEPENDS+=	p5-XML-AutoWriter>=0.38:../../textproc/p5-XML-AutoWriter
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		auto/VCP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
