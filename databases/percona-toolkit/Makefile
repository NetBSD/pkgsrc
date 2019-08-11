# $NetBSD: Makefile,v 1.24 2019/08/11 13:18:36 wiz Exp $
#

DISTNAME=	percona-toolkit-3.0.12
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/percona-toolkit/${PKGVERSION_NOREV}/source/tarball/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://www.percona.com/software/percona-toolkit/
COMMENT=	Advanced command-line tools for open-source databases (MySQL)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl bash:run sh:run

REPLACE_PERL+=	bin/*

# Fix paths to bash and sh that were replaced by Perl's MakeMaker to
# point to the programs in the tools directory.
#
SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-build
SUBST_FILES.bash=	blib/script/pt-ioprofile
SUBST_FILES.bash+=	blib/script/pt-pmp
SUBST_FILES.bash+=	blib/script/pt-sift
SUBST_FILES.bash+=	blib/script/pt-stalk
SUBST_SED.bash+=	-e 's|^\#!.*|\#!${TOOLS_PATH.bash}|'

SUBST_CLASSES+=		sh
SUBST_STAGE.sh=		post-build
SUBST_FILES.sh=		blib/script/pt-mext
SUBST_FILES.sh+=	blib/script/pt-mysql-summary
SUBST_FILES.sh+=	blib/script/pt-summary
SUBST_SED.sh+=		-e 's|^\#!.*|\#!${TOOLS_PATH.sh}|'

DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/percona-toolkit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
