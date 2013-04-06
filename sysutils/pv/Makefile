# $NetBSD: Makefile,v 1.22 2013/04/06 04:11:44 rodent Exp $
#

DISTNAME=		pv-0.9.6
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ivarch.com/programs/sources/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=pipeviewer/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ivarch.com/programs/pv.shtml
COMMENT=		Monitor the progress of data through a pipeline

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes
INFO_FILES=		# PLIST

# Don't gzip the installed info file and man pages.
CONFIGURE_ENV+=		DO_GZIP=${TOOLS_CMD.true}

DOCDIR=			${PREFIX}/share/doc/pv
INSTALLATION_DIRS=	${DOCDIR}

# Grab list of files to install from the PLIST.
post-install:
	dir=${DOCDIR:S/^${PREFIX}\///:Q}; cd ${WRKSRC}/doc;		\
	${GREP} "^$$dir/" ${PKGDIR}/PLIST | ${SED} "s|^$$dir/||" |	\
	while read file; do						\
		${TEST} ! -f "$$file" ||					\
			${INSTALL_DATA} "$$file" ${DESTDIR}${PREFIX}/$$dir; \
	done
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
