# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:50 obache Exp $
#

DISTNAME=		refinecvs-0.86.1251
PKGREVISION=		3
CATEGORIES=		devel scm
MASTER_SITES=		http://lev.serebryakov.spb.ru/refinecvs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lev.serebryakov.spb.ru/refinecvs/
COMMENT=		Convert CVS repository to SVN dump

PKG_DESTDIR_SUPPORT=	user-destdir

do-configure:	# nothing

do-build:	# nothing

REPLACE_PERL=	refinecvs.pl

LIBDIR=	${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}/Cvs/Repository

INSTALLATION_DIRS=	bin ${LIBDIR} share/doc/refinecvs

do-install:
	for f in DeltaCache.pm Delta.pm Exception.pm File.pm Reader.pm Revision.pm ; do \
		${INSTALL_DATA} ${WRKSRC}/Cvs/Repository/$$f ${DESTDIR}${LIBDIR}/$$f; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/refinecvs.pl ${DESTDIR}${PREFIX}/bin/refinecvs
	for f in Changes LICENSE README TODO ; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/doc/refinecvs/$$f; \
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
