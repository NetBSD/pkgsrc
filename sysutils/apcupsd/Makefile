# $NetBSD: Makefile,v 1.11 2001/08/01 16:55:38 wiz Exp $
#

DISTNAME=		apcupsd-3.6.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.oasi.gpa.it/pub/apcupsd/stable/tar/

MAINTAINER=		bouyer@netbsd.org
HOMEPAGE=		http://www.sibbald.com/apcupsd/
COMMENT=		UPS power management for APCC Products

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_USES_MSGFMT=	yes

USE_GMAKE=		# defined
#USE_LIBINTL=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-http		# include http support

# Thread support is needed to compile powerflute, which has a curses interface
#
#DEPENDS+=		ncurses-*:../../devel/ncurses
#CONFIGURE_ARGS+=	--enable-threads	# compile threading code
#CONFIGURE_ARGS+=	--enable-powerflute	# compile powerflute program

CONFIGURE_ARGS+=	--with-catgets		# use catgets functions
CONFIGURE_ARGS+=	--enable-nls		# i18n support

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf --force

# we should probably allow the tty to be set in /etc/mk.conf too
#
post-build:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' ${WRKSRC}/examples/apcupsd.conf > \
		${WRKDIR}/apcupsd.conf
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' ${FILESDIR}/apcupsd > \
		${WRKDIR}/apcupsd
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' ${WRKSRC}/doc/apcupsd.man > \
		${WRKSRC}/doc/apcupsd.8

DOCS=	README.BackUPS-Pro	\
	README.NEW		\
	README.NewerBackUPS-Pro	\
	README.Share-UPS	\
	README.SmartUPS-VS	\
	README.apcaccess	\
	README.autoconfig	\
	README.cable		\
	README.developers	\
	Statement.APCC 		\
	minicom.apcupsd		\
	port.gif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples
	${INSTALL_DATA} ${WRKDIR}/apcupsd.conf ${PREFIX}/share/examples
	${INSTALL_SCRIPT} ${WRKDIR}/apcupsd ${PREFIX}/etc/rc.d
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/apcupsd
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/apcupsd
.endfor

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
