# $NetBSD: Makefile,v 1.19 2001/08/06 14:20:46 jlam Exp $
#

DISTNAME=	readline-4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/readline/
COMMENT=	GNU library that can recall and edit previous input

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

ALL_TARGET=		all-la
INSTALL_TARGET=		install-la

INFO_FILES=		readline.info history.info

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

.include "../../mk/bsd.pkg.mk"
