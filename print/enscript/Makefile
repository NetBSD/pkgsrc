# New ports collection makefile for:	enscript
# Version required:     	1.5.0
# Date created:			24 Jul, 1997
# Whom:				kline
#
# $NetBSD: Makefile,v 1.2 1998/02/22 17:21:41 frueauf Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=       enscript-1.5.0
PKGNAME=        enscript-${PAPERSIZE}-1.5.0
CATEGORIES=	print
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	kline@thought.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to Letter A4
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-media=${PAPERSIZE}
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_FLAGS=     WIDTH=${WIDTH} HEIGHT=${HEIGHT} A4_PAPERSIZE=${A4_PAPERSIZE} -f

MAN1=		diffpp.1 enscript.1 sliceprint.1 states.1
STRIP=

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

# Include local make config file here.  It is essential to have this
# precede any override targets (those that override defaults in
# <bsd.port.mk> that test variables that may be set here.  Note that
# this inclusion is otherwise redundant, since <bsd.port.mk> includes
# <bsd.own.mk>, which includes it.

OPSYS!=		uname -s
.if (${OPSYS} == "FreeBSD")
.if exists(/etc/make.conf)
.include "/etc/make.conf"
.endif
.else
.if exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif
.endif

.if !defined(PAPERSIZE)
PAPERSIZE=A4     # set default
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
PAPERSIZE_UNSPECIFIED=  yes
.elif ${PAPERSIZE} == A4 || ${PAPERSIZE} == a4
PAPERSIZE=A4
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
.elif ${PAPERSIZE} == letter || ${PAPERSIZE} == LETTER || ${PAPERSIZE} == Letter
PAPERSIZE=Letter
WIDTH=8.5
HEIGHT=11.0
A4_PAPERSIZE=0
.elif ${PAPERSIZE} == Letterdj
.else
PAPERSIZE_INVALID= yes
.endif  # not defined PAPERSIZE

pre-fetch:
.if defined(PAPERSIZE_UNSPECIFIED)
	@${ECHO} ""
	@${ECHO} "This port builds the default A4 paper size."
	@${ECHO} "If you want to select the LETTER papersize for enscript,"
	@${ECHO} "type a ^C now.  Then type:"
	@${ECHO} ""
	@${ECHO} "  % make letter "
	@${ECHO} ""
	@${ECHO} "Install your port by typing:"
	@${ECHO} ""
	@${ECHO} "make letter-install  {or} % make a4-install"
	@${ECHO} ""
	@${ECHO} "You can also set the environment variable PAPERSIZE to A4 or"
	@${ECHO} "Letter to configure enscript for these paper sizes"
	@sleep 5
.elif defined(PAPERSIZE_INVALID)
	@${ECHO} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  A4 (default) or Letter"
	@${FALSE}
.endif

letter::
	${MAKE} PAPERSIZE=Letter

Letter::
	${MAKE} PAPERSIZE=Letter

letter-install::
	${MAKE} PAPERSIZE=Letter install

Letter-install::
	${MAKE} PAPERSIZE=Letter install

a4::
	${MAKE} PAPERSIZE=A4

A4::
	${MAKE} PAPERSIZE=A4

Letterdj::
	${MAKE} PAPERSIZE=Letterdj

letterdj::
	${MAKE} PAPERSIZE=Letterdj

Letterdj-install::
	${MAKE} PAPERSIZE=Letterdj install

letterdj-install::
	${MAKE} PAPERSIZE=Letterdj install

a4-install::
	${MAKE} PAPERSIZE=a4 install

A4-install::
	${MAKE} PAPERSIZE=a4 install

post-install:
.for file in enscript mkafmmap states
	strip ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
