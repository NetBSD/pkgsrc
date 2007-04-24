# $NetBSD: Makefile,v 1.1.1.1 2007/04/24 16:34:01 dmcmahill Exp $
#

PKGVER=		1.5.0.3
DISTNAME=	git-${PKGVER}
PKGNAME=	git-fvcs-${PKGVER}
CATEGORIES=	devel
MASTER_SITES=	http://kernel.org/pub/software/scm/git/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://git.or.cz/
COMMENT=	Popular version control system designed to handle large projects

EXTRACT_USING=	gtar

CONFLICTS+=	git-[0-9]*

USE_TOOLS+=	gmake perl:run wish:run

REPLACE_PERL+=	git-add--interactive.perl git-archimport.perl \
		git-cvsexportcommit.perl git-cvsimport.perl \
		git-cvsserver.perl git-remote.perl \
		git-send-email.perl git-svnimport.perl \
		Documentation/build-docdep.perl Documentation/sort_glossary.pl \
		gitweb/gitweb.perl \
		contrib/blameview/blameview.perl contrib/fast-import/import-tars.perl

PYTHON_PATCH_SCRIPTS+=	git-p4import.py contrib/hg-to-git/hg-to-git.py

PERL5_PACKLIST_DIR=	${PREFIX}/lib/perl5/site_perl/5.8.0/${MACHINE_ARCH}-${LOWER_OPSYS}-thread-multi
PERL5_PACKLIST= 	auto/Git/.packlist

do-build:
	cd ${WRKSRC} && ${GMAKE} prefix=${PREFIX} PERL_PATH=${PREFIX}/bin/perl CC=${CC:Q}

do-install:
	cd ${WRKSRC} && ${GMAKE} prefix=${PREFIX} PERL_PATH=${PREFIX}/bin/perl INSTALL=${INSTALL:Q} install

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
