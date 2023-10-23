# $NetBSD: batteries-included.mk,v 1.1 2023/10/23 06:35:59 wiz Exp $
#
# Makefile fragment that pulls in the required Python versions
# that provide formerly separately packaged Python modules.

BUILDLINK_API_DEPENDS.python27+=	python27-2.7.18nb12
BUILDLINK_API_DEPENDS.python38+=	python38-3.8.18nb1
BUILDLINK_API_DEPENDS.python39+=	python39-3.9.18nb1
BUILDLINK_API_DEPENDS.python310+=	python310-3.10.13nb1
BUILDLINK_API_DEPENDS.python311+=	python311>=3.11.6nb1
BUILDLINK_API_DEPENDS.python312+=	python312-3.12.0nb1
