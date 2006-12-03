# $NetBSD: l10n.mk,v 1.1 2006/12/03 04:03:06 markd Exp $
#

# This file provides useful defaults for the l10n packages of koffice.
#
# The following variables shall be defined when using this file.
#
# KOFFICE_LANGCODE
#	The language code (e.g. de, pt_BR)
#
# KOFFICE_LANGUAGE
#	The full name of the language (e.g. German, Brasilian)
#

KOFFICE_VERSION?=	1.6.1

DISTNAME=	koffice-l10n-${KOFFICE_LANGCODE}-${KOFFICE_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-${KOFFICE_VERSION}/src/koffice-l10n/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	${KOFFICE_LANGUAGE} language pack for KOffice

BUILD_DEPENDS+=	kdelibs>=3:../../x11/kdelibs3
CONFLICTS+=	koffice-i18n-${KOFFICE_LANGCODE}-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt

SUBST_CLASSES+=		ko
SUBST_MESSAGE.ko=	Dont try to install kdgantt.po
SUBST_STAGE.ko=		pre-configure
SUBST_FILES.ko=		messages/koffice/Makefile.in
SUBST_SED.ko=		-e 's/ kdgantt / /'

.include "../../meta-pkgs/kde3/kde3.mk"
