# $NetBSD: Makefile,v 1.6 1998/06/22 13:04:38 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=		enscript-1.6.0
PKGNAME=		enscript-${PAPERSIZE}-1.6.0
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU}

MAINTAINER=		packages@netbsd.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to Letter or A4
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-nls --with-media=${PAPERSIZE}
CONFIGURE_ENV=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=		`${CAT} ${PAPER}`

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=		-static

PAPERSIZE?=		A4
PAPER=			${.CURDIR}/${WRKDIR:T}/PaperSize

pre-configure:
	@case "X${PAPERSIZE}" in					\
	XA4)								\
		${ECHO} "WIDTH=8.27 HEIGHT=11.64" > ${PAPER};		\
		;;							\
	XLetter)							\
		${ECHO} "WIDTH=8.5 HEIGHT=11.0" > ${PAPER};		\
		;;							\
	XLetterdj)							\
		;;							\
	*)								\
		@${ECHO} "Error: PAPERSIZE invalid: \"${PAPERSIZE}\"";	\
		@${ECHO} "Possible values are:  A4 (default) or Letter";\
		${FALSE};						\
		;;							\
	esac

post-install:
.for file in enscript mkafmmap states
	strip ${PREFIX}/bin/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
