# $NetBSD: Makefile,v 1.23 2010/02/19 15:34:10 joerg Exp $
#

DISTNAME=	stylewriter
PKGNAME=	stylewriter-0.9.9
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://homepage.mac.com/monroe/styl/
COMMENT=	Apple StyleWriter driver for un*x

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	enscript>=1.6.3nb1:../../print/enscript

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=	gs:run
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	sbin

PLIST_SRC=	${WRKDIR}/PLIST
FILTER_DIR=	libexec/stylewriter
FILTERS=	direct_stylpbm direct_stylps \
		stylascii stylascii.a4 \
		stylps stylps-color stylps-color.a4 stylps.a4
FILTER_SED=	-e "s,/usr/local/gnu/bin/gs,${LOCALBASE}/bin/gs,g" \
		-e "s,/usr/local,${PREFIX},g"
PRINTCAP_SED=	-e "s,/var/spool/stylps,/var/spool/lpd/stylps,g" \
		-e "s,/usr/local/sbin,${PREFIX}/libexec/stylewriter,g"

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

INSTALLATION_DIRS+=	${FILTER_DIR} share/doc/stylewriter share/examples/stylewriter

OWN_DIRS+=	/var/spool/lpd/stylps

post-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	(cd ${WRKSRC}/scripts; \
	 for FILTER in ${FILTERS}; do \
		${SED} ${FILTER_SED} \
			< $${FILTER} > ${WRKDIR}/$${FILTER}; \
		${INSTALL_SCRIPT} ${WRKDIR}/$${FILTER} \
			${DESTDIR}${PREFIX}/${FILTER_DIR}/$${FILTER}; \
		${RM} ${WRKDIR}/$${FILTER}; \
	 done)

	for FILE in README README.protocol README.troubleshooting; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} \
			${DESTDIR}${PREFIX}/share/doc/stylewriter; \
	done

	(cd ${WRKSRC}; \
	 for PRINTCAP in printcap printcap.a4; do \
		${SED} ${PRINTCAP_SED} \
			< $${PRINTCAP} > ${WRKDIR}/$${PRINTCAP}; \
		${INSTALL_DATA} ${WRKDIR}/$${PRINTCAP} \
			${DESTDIR}${PREFIX}/share/examples/stylewriter; \
		${RM} ${WRKDIR}/$${PRINTCAP}; \
	 done)
	${INSTALL_DATA} ${WRKSRC}/styl.ppd ${DESTDIR}${PREFIX}/share/examples/stylewriter

.include "../../mk/bsd.pkg.mk"
