# $NetBSD: Makefile,v 1.5 2001/08/16 08:13:43 jlam Exp $
#

DISTNAME=	tnef-1.1
CATEGORIES=	mail
MASTER_SITES=	http://world.std.com/~damned/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://world.std.com/~damned/software.html
COMMENT=	decode MS-TNEF MIME attachments

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined

# Change references to tnef.3 to tnef.1.
post-extract:
	cd ${WRKSRC}; ${MV} doc/tnef.3 doc/tnef.1

post-patch:
	cd ${WRKSRC}; for file in doc/Makefile.in; do			\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|man3|man1|g" -e "s|\.3|.1|g"		\
			$${file}.fixme > $${file};			\
		if [ -x $${file}.fixme ]; then				\
			${CHMOD} +x $${file};				\
		fi;							\
		${RM} -f $${file}.fixme;				\
	done

.include "../../mk/bsd.pkg.mk"
