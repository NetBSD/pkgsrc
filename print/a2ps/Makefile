# New ports collection makefile for:    a2ps
# Version required:     4.9.9
# Date created:         18 August 1997
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $NetBSD: Makefile,v 1.5 1998/02/22 17:11:53 frueauf Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/15 21:24:42 steve Exp
#

DISTNAME=	a2ps-4.9.9
PKGNAME=	a2ps-${PAPERSIZE}-4.9.9
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/

MAINTAINER=	chuckr@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		a2ps.1 ogonkify.1

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

PAPERSIZE?=
STRIP=
CONFIGURE_ARGS+=	--with-medium=${PAPERSIZE}
CONFIGURE_ENV+=		LPR=lpr

ALL_TARGET=	all PAPERSIZE=${PAPERSIZE}

Letter::
	$(MAKE) PAPERSIZE=Letter

letter::
	$(MAKE) PAPERSIZE=Letter

Letterdj::
	$(MAKE) PAPERSIZE=Letterdj

letterdj::
	$(MAKE) PAPERSIZE=Letterdj

A4::
	$(MAKE) PAPERSIZE=A4

a4::
	$(MAKE) PAPERSIZE=A4

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

pre-extract:
.if empty(PAPERSIZE)
	@${ECHO}
	@${ECHO} "PAPERSIZE not specified."
	@${ECHO}
	@${ECHO} "Must specify PAPERSIZE as one of A4, Letter, or Letterdj,"
	@${ECHO} "either using setenv, or via Makefile targets of the same"
	@${ECHO} "name. Note that each PAPERSIZE has a leading capital letter,"
	@${ECHO} "and Letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.elif $(PAPERSIZE)!=A4 && $(PAPERSIZE)!=Letter && $(PAPERSIZE)!=Letterdj
	@${ECHO}
	@${ECHO} "PAPERSIZE incorrect value: $(PAPERSIZE)."
	@${ECHO}
	@${ECHO} "Must specify PAPERSIZE as one of A4, Letter, or Letterdj,"
	@${ECHO} "either using setenv, or via Makefile targets of the same"
	@${ECHO} "name. Note that each PAPERSIZE has a leading capital letter,"
	@${ECHO} "and Letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.endif

.include <bsd.port.mk>
