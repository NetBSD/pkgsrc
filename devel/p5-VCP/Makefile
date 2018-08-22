# $NetBSD: Makefile,v 1.20 2018/08/22 09:44:54 wiz Exp $

DISTNAME=	VCP-autrijus-snapshot-0.9-${SNAPSHOT_VERS}
SNAPSHOT_VERS=	20050110
PKGNAME=	p5-${DISTNAME:S/-autrijus-snapshot-/-/:S/-${SNAPSHOT_VERS}$/beta${SNAPSHOT_VERS}/}
PKGREVISION=	11
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/A/AU/AUTRIJUS

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Versioned Copy, copying hierarchies of versioned files
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=		no

#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
#DEPENDS+=	{perl>=5.6.1,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Regexp-Shellish>=0.93:../../devel/p5-Regexp-Shellish
DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff
DEPENDS+=	p5-XML-AutoWriter>=0.38:../../textproc/p5-XML-AutoWriter
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		auto/VCP/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
