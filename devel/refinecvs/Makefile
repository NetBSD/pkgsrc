# $NetBSD: Makefile,v 1.1.1.1 2005/12/04 17:52:23 mjl Exp $
#

DISTNAME=		refinecvs-0.86.1251
CATEGORIES=		devel
MASTER_SITES=		http://lev.serebryakov.spb.ru/refinecvs/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://lev.serebryakov.spb.ru/refinecvs/
COMMENT=		Convert CVS repository to SVN dump

do-configure:	# nothing

do-build:	# nothing

REPLACE_PERL=	refinecvs.pl

LIBDIR=	${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}/Cvs/Repository

do-install:
	${INSTALL_LIB_DIR} ${LIBDIR}
	for f in DeltaCache.pm Delta.pm Exception.pm File.pm Reader.pm Revision.pm ; do \
		${INSTALL_DATA} ${WRKSRC}/Cvs/Repository/$$f ${LIBDIR}/$$f; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/refinecvs.pl ${PREFIX}/bin/refinecvs
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/refinecvs
	for f in Changes LICENSE README TODO ; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/refinecvs/$$f; \
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
