# $NetBSD: Makefile,v 1.4 2020/03/20 15:45:12 rillig Exp $

DISTNAME=	show-all-1.0
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Demonstrates the show-all target
LICENSE=	2-clause-bsd

REGRESS.empty=		# empty
REGRESS.space=		${:U } # a single space
REGRESS.value=		All * kinds of `strange' \escape $$characters

REGRESS_ENV.empty=	# empty
REGRESS_ENV.space=	${:U } # a single space
REGRESS_ENV.value=	VAR1=value1 VAR2=`command execution via backticks` *=all

REGRESS_ARGS.empty=	# empty
REGRESS_ARGS.space=	${:U } # a single space
REGRESS_ARGS.value=	VAR1=value1 VAR2=`command execution via backticks` *=all

# Variable names may also contain special characters that must be escaped.
*=			bmake built-in
**=			asterisk

_VARGROUPS+=		regress
_PKG_VARS.regress+=	REGRESS_ENV.undefined REGRESS_ENV.empty REGRESS_ENV.space REGRESS_ENV.value
_PKG_VARS.regress+=	REGRESS_ARGS.undefined REGRESS_ARGS.empty REGRESS_ARGS.space REGRESS_ARGS.value
_PKG_VARS.regress+=	REGRESS.undefined REGRESS.empty REGRESS.space REGRESS.value
_PKG_VARS.regress+=	* **
_SORTED_VARS.regress=	*_ENV.*
_LISTED_VARS.regress=	*_ARGS.*

SHELLVAR_PLAIN=		"$$var $${var} $$other"
SHELLVAR_ENV=		"$$var $${var} $$other"
SHELLVAR_ARGS=		"$$var $${var} $$other"

_VARGROUPS+=		shellvar
_PKG_VARS.shellvar=	SHELLVAR_PLAIN SHELLVAR_ENV SHELLVAR_ARGS
_SORTED_VARS.shellvar=	*_ENV
_LISTED_VARS.shellvar=	*_ARGS

.include "../../mk/bsd.pkg.mk"
