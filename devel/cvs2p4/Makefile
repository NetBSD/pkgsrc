# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:45 jlam Exp $
#

DISTNAME=	cvs2p4-2.3.3
CATEGORIES=	devel
MASTER_SITES=	ftp://public.perforce.com/public/perforce/utils/cvs2p4/
EXTRACT_SUFX=	.tar

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Converts CVS repository to Perforce depot

DEPENDS+=	p4-[0-9]*:../../devel/p4
DEPENDS+=	p4d-[0-9]*:../../devel/p4d
.if !exists(/usr/bin/co) && !exists(${LOCALBASE}/bin/co)
DEPENDS+=	rcs-[0-9]*:../../devel/rcs
.endif

USE_PKGINSTALL=	yes
USE_PERL5=	yes
NO_BUILD=	yes

DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}
LIBDIR=		lib/perl5
PLIST_SUBST+=	DOCDIR=${DOCDIR}
PLIST_SUBST+=	EGDIR=${EGDIR}

FILES_SUBST+=	P4ROOT=${P4ROOT:Q}
FILES_SUBST+=	P4PORT=${P4PORT:Q}

CVS2P4_INLIB=	$$Mydir/lib/util\.pl
CVS2P4_OUTLIB=	${LIBDIR}/${PKGBASE}-util.pl

INSTALLATION_DIRS=	bin ${LIBDIR}

do-configure:
	for f in ${WRKSRC}/bin/*; do \
		( ${ECHO} \#!${PERL5}; ${CAT} $${f} ) | ${SED} -e '2,5d' \
			-e 's|${CVS2P4_INLIB}|${PREFIX}/${CVS2P4_OUTLIB}|' \
			> $${f}.new; \
		${MV} -f $${f}.new $${f}; \
	done
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/test/config \
		> ${WRKSRC}/test/config.new
	@${MV} -f ${WRKSRC}/test/config.new ${WRKSRC}/test/config

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/util.pl ${PREFIX}/${CVS2P4_OUTLIB}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin

	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/${DOCDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/test/config ${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
