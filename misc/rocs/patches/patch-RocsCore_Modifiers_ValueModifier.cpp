$NetBSD: patch-RocsCore_Modifiers_ValueModifier.cpp,v 1.1 2013/11/29 12:52:21 joerg Exp $

--- RocsCore/Modifiers/ValueModifier.cpp.orig	2013-11-27 12:51:22.000000000 +0000
+++ RocsCore/Modifiers/ValueModifier.cpp
@@ -44,8 +44,8 @@ void ValueModifier::enumerate(const QLis
         list[i]->setProperty(property.toLatin1(), baseString + QString::number(start++));
     }
 }
-template void ValueModifier::enumerate<DataPtr>(const QList<DataPtr> &list, const QString &property, int start, const QString &baseString, bool overrideValues);
-template void ValueModifier::enumerate<PointerPtr>(const QList<PointerPtr> &list, const QString &property, int start, const QString &baseString, bool overrideValues);
+template ROCSLIB_EXPORT void ValueModifier::enumerate<DataPtr>(const QList<DataPtr> &list, const QString &property, int start, const QString &baseString, bool overrideValues);
+template ROCSLIB_EXPORT void ValueModifier::enumerate<PointerPtr>(const QList<PointerPtr> &list, const QString &property, int start, const QString &baseString, bool overrideValues);
 
 
 template<typename T>
@@ -81,8 +81,8 @@ void ValueModifier::enumerateAlpha(const
         }
     }
 }
-template void ValueModifier::enumerateAlpha<DataPtr>(const QList<DataPtr> &list, const QString &property, const QString &start, bool overrideValues);
-template void ValueModifier::enumerateAlpha<PointerPtr>(const QList<PointerPtr> &list, const QString &property, const QString &start, bool overrideValues);
+template ROCSLIB_EXPORT void ValueModifier::enumerateAlpha<DataPtr>(const QList<DataPtr> &list, const QString &property, const QString &start, bool overrideValues);
+template ROCSLIB_EXPORT void ValueModifier::enumerateAlpha<PointerPtr>(const QList<PointerPtr> &list, const QString &property, const QString &start, bool overrideValues);
 
 
 template<typename T>
@@ -105,8 +105,8 @@ void ValueModifier::assignRandomIntegers
         list[i]->setProperty(property.toLatin1(), QString::number(die()));
     }
 }
-template void ValueModifier::assignRandomIntegers<DataPtr>(const QList<DataPtr> &list, const QString &property, int lowerLimit, int upperLimit, int seed, bool overrideValues);
-template void ValueModifier::assignRandomIntegers<PointerPtr>(const QList<PointerPtr> &list, const QString &property, int lowerLimit, int upperLimit, int seed, bool overrideValues);
+template ROCSLIB_EXPORT void ValueModifier::assignRandomIntegers<DataPtr>(const QList<DataPtr> &list, const QString &property, int lowerLimit, int upperLimit, int seed, bool overrideValues);
+template ROCSLIB_EXPORT void ValueModifier::assignRandomIntegers<PointerPtr>(const QList<PointerPtr> &list, const QString &property, int lowerLimit, int upperLimit, int seed, bool overrideValues);
 
 
 template<typename T>
@@ -129,8 +129,8 @@ void ValueModifier::assignRandomReals(co
         list[i]->setProperty(property.toLatin1(), QString::number(die()));
     }
 }
-template void ValueModifier::assignRandomReals<DataPtr>(const QList<DataPtr> &list, const QString &property, qreal lowerLimit, qreal upperLimit, int seed, bool overrideValues);
-template void ValueModifier::assignRandomReals<PointerPtr>(const QList<PointerPtr> &list, const QString &property, qreal lowerLimit, qreal upperLimit, int seed, bool overrideValues);
+template ROCSLIB_EXPORT void ValueModifier::assignRandomReals<DataPtr>(const QList<DataPtr> &list, const QString &property, qreal lowerLimit, qreal upperLimit, int seed, bool overrideValues);
+template ROCSLIB_EXPORT void ValueModifier::assignRandomReals<PointerPtr>(const QList<PointerPtr> &list, const QString &property, qreal lowerLimit, qreal upperLimit, int seed, bool overrideValues);
 
 template<typename T>
 void ValueModifier::assignConstantValue(const QList<T> &list, const QString &property, const QString &constant, bool overrideValues)
@@ -142,5 +142,5 @@ void ValueModifier::assignConstantValue(
         list[i]->setProperty(property.toLatin1(), constant);
     }
 }
-template void ValueModifier::assignConstantValue<DataPtr>(const QList<DataPtr> &list, const QString &property, const QString &constant, bool overrideValues = true);
-template void ValueModifier::assignConstantValue<PointerPtr>(const QList<PointerPtr> &list, const QString &property, const QString &constant, bool overrideValues = true);
+template ROCSLIB_EXPORT void ValueModifier::assignConstantValue<DataPtr>(const QList<DataPtr> &list, const QString &property, const QString &constant, bool overrideValues = true);
+template ROCSLIB_EXPORT void ValueModifier::assignConstantValue<PointerPtr>(const QList<PointerPtr> &list, const QString &property, const QString &constant, bool overrideValues = true);
