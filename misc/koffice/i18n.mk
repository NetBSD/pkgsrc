# $NetBSD: i18n.mk,v 1.1 2006/10/24 07:34:13 rillig Exp $
#

# This file provides useful defaults for the i18n packages of koffice.
#
# The following variables shall be defined when using this file.
#
# KOFFICE_LANGCODE
#	The language code (e.g. de, pt_BR)
#
# KOFFICE_LANGUAGE
#	The full name of the language (e.g. German, Brasilian)
#

KOFFICE_VERSION?=	1.3.5

DISTNAME=	koffice-i18n-${KOFFICE_LANGCODE}-${KOFFICE_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-${KOFFICE_VERSION}/src/koffice-l10n/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER?=	ianzag@mail.ru
HOMEPAGE=	http://www.koffice.org/
COMMENT=	${KOFFICE_LANGUAGE} language pack for KOffice

BUILD_DEPENDS+=	kdelibs>=3:../../x11/kdelibs3
CONFLICTS+=	koffice-l10n-${KOFFICE_LANGCODE}-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

SUBST_CLASSES+=		ko
SUBST_STAGE.ko=		pre-configure
SUBST_FILES.ko=		configure
SUBST_SED.ko=		-e 's,\(build_arts" \)==\( "no"\),\1=\2,'
