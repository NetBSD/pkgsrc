# $NetBSD: Makefile,v 1.31 2001/11/29 01:12:47 hubertf Exp $
#

V=		2.05
DV=		2.05
DISTNAME=	bash-${V}
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://slc2.ins.cwru.edu/pub/dist/
DISTFILES=      bash-${V}.tar.gz bash-doc-${DV}.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_GTEXINFO=		yes
MAKE_ENV+=		INSTALL_SCRIPT='${INSTALL_SCRIPT}'

.include "../../mk/bsd.prefs.mk"

.if defined(BASH_STATIC) && ${BASH_STATIC} == YES
CONFIGURE_ARGS+=	--enable-static-link
.endif

# Remove -I$(includedir) from the INCLUDES passed to the compiler as this
# defeats buildlink.
#
post-patch:
	cd ${WRKSRC};							\
	files="Makefile.in";						\
	for file in $${files}; do					\
		${MV} -f $${file} $${file}.fixme;			\
		${SED} -e "s|[  ]*-I\$$(includedir)||"			\
			$${file}.fixme > $${file};			\
		${RM} $${file}.fixme;					\
	done

post-install:
	${TOUCH} /etc/shells
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/bash /etc/shells.bak || ${TRUE}; ${ECHO} ${PREFIX}/bin/bash) >/etc/shells
	${RM} /etc/shells.bak
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.ps  \
		${WRKDIR}/doc/bashref.ps  \
		${WRKDIR}/doc/article.txt  \
		${PREFIX}/share/doc/bash
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bash
	${INSTALL_MAN} \
		${WRKDIR}/doc/bash.html  \
		${WRKDIR}/doc/bashref.html  \
		${PREFIX}/share/doc/html/bash
	${GZIP_CMD} ${PREFIX}/share/doc/bash/*.ps

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
