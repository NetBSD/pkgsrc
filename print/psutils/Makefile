# New ports collection makefile for:    psutils
# Version required:     1.16
# Date created:         21 September 1994
# Whom:                 jmz & David O'Brien (obrien@cs.ucdavis.edu)
#
# $NetBSD: Makefile,v 1.2 1998/02/22 20:37:58 frueauf Exp $
# FreeBSD Id: Makefile,v 1.15 1998/01/08 18:52:13 fenner Exp
#

DISTNAME=	psutils-p17
PKGNAME=	psutils-${PAPERSIZE}-1.17
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/

MAINTAINER=	jmz@FreeBSD.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to letter A4
WRKSRC=		${WRKDIR}/psutils
MAKE_FLAGS?=	PAPER=${PAPERSIZE} -f
MAN1=		psbook.1 psselect.1 pstops.1 epsffit.1 psnup.1 psresize.1 \
		getafm.1 fixdlsrps.1 fixfmps.1 fixmacps.1 fixpsditps.1 \
		fixpspps.1 fixtpps.1 fixwfwps.1 fixwpps.1 fixwwps.1 \
		extractres.1 includeres.1 fixscribeps.1 psmerge.1

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
PAPERSIZE=A4
PAPERSIZE_UNSPECIFIED=	yes
.else
.if ${PAPERSIZE} != A3 && ${PAPERSIZE} != a3 && ${PAPERSIZE} != A4 \
	&& ${PAPERSIZE} != a4 && ${PAPERSIZE} != A5 && ${PAPERSIZE} != a5 \
	&& ${PAPERSIZE} != B5 && ${PAPERSIZE} != b5 \
	&& ${PAPERSIZE} != letter && ${PAPERSIZE} != legal \
	&& ${PAPERSIZE} != ledger && ${PAPERSIZE} != tabloid \
	&& ${PAPERSIZE} != statement && ${PAPERSIZE} != executive \
	&& ${PAPERSIZE} != folio && ${PAPERSIZE} != quarto \
	&& ${PAPERSIZE} != 10x14
PAPERSIZE_INVALID= yes
.endif
.endif

pre-fetch:
.if defined(PAPERSIZE_UNSPECIFIED)
	@${ECHO} "Defaulting to ${PAPERSIZE} sized paper."
	@${ECHO} ""
	@${ECHO} "Set the environment variable PAPERSIZE if you want to use"
	@${ECHO} "other sizes. Possible values are:"
	@${ECHO} "   A3, A4 (default), A5, B5, letter, legal, ledger, tabloid,"
	@${ECHO} "   statement, executive, folio, quarto, and 10x14."
.elif defined(PAPERSIZE_INVALID)
	@${ECHO} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:"
	@${ECHO} "   A3, A4 (default), A5, B5, letter, legal, ledger, tabloid,"
	@${ECHO} "   statement, executive, folio, quarto, and 10x14."
	@${FALSE}
.endif

post-install:
.for file in epsffit psbook psnup psresize psselect pstops
	strip ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
