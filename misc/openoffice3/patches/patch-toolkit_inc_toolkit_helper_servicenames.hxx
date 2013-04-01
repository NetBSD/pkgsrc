$NetBSD: patch-toolkit_inc_toolkit_helper_servicenames.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- toolkit/inc/toolkit/helper/servicenames.hxx.orig	2013-03-30 22:15:11.000000000 +0000
+++ toolkit/inc/toolkit/helper/servicenames.hxx
@@ -34,73 +34,73 @@
 #include <sal/types.h>
 #include <tools/solar.h>
 
-extern const sal_Char __FAR_DATA szServiceName_Toolkit[], szServiceName2_Toolkit[];
-extern const sal_Char __FAR_DATA szServiceName_MVCIntrospection[], szServiceName2_MVCIntrospection[];
-extern const sal_Char __FAR_DATA szServiceName_PopupMenu[], szServiceName2_PopupMenu[];
-extern const sal_Char __FAR_DATA szServiceName_MenuBar[], szServiceName2_MenuBar[];
-extern const sal_Char __FAR_DATA szServiceName_Pointer[], szServiceName2_Pointer[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlContainer[], szServiceName2_UnoControlContainer[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlContainerModel[], szServiceName2_UnoControlContainerModel[];
-extern const sal_Char __FAR_DATA szServiceName_TabController[], szServiceName2_TabController[];
-extern const sal_Char __FAR_DATA szServiceName_TabControllerModel[], szServiceName2_TabControllerModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlDialog[], szServiceName2_UnoControlDialog[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlDialogModel[], szServiceName2_UnoControlDialogModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlEdit[], szServiceName2_UnoControlEdit[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlEditModel[], szServiceName2_UnoControlEditModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFileControl[], szServiceName2_UnoControlFileControl[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFileControlModel[], szServiceName2_UnoControlFileControlModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlButton[], szServiceName2_UnoControlButton[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlButtonModel[], szServiceName2_UnoControlButtonModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlImageButton[], szServiceName2_UnoControlImageButton[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlImageButtonModel[], szServiceName2_UnoControlImageButtonModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlImageControl[], szServiceName2_UnoControlImageControl[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlImageControlModel[], szServiceName2_UnoControlImageControlModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlRadioButton[], szServiceName2_UnoControlRadioButton[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlRadioButtonModel[], szServiceName2_UnoControlRadioButtonModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlCheckBox[], szServiceName2_UnoControlCheckBox[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlCheckBoxModel[], szServiceName2_UnoControlCheckBoxModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlListBox[], szServiceName2_UnoControlListBox[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlListBoxModel[], szServiceName2_UnoControlListBoxModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlComboBox[], szServiceName2_UnoControlComboBox[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlComboBoxModel[], szServiceName2_UnoControlComboBoxModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFixedText[], szServiceName2_UnoControlFixedText[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFixedTextModel[], szServiceName2_UnoControlFixedTextModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlGroupBox[], szServiceName2_UnoControlGroupBox[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlGroupBoxModel[], szServiceName2_UnoControlGroupBoxModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlDateField[], szServiceName2_UnoControlDateField[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlDateFieldModel[], szServiceName2_UnoControlDateFieldModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlTimeField[], szServiceName2_UnoControlTimeField[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlTimeFieldModel[], szServiceName2_UnoControlTimeFieldModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlNumericField[], szServiceName2_UnoControlNumericField[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlNumericFieldModel[], szServiceName2_UnoControlNumericFieldModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlCurrencyField[], szServiceName2_UnoControlCurrencyField[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlCurrencyFieldModel[], szServiceName2_UnoControlCurrencyFieldModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlPatternField[], szServiceName2_UnoControlPatternField[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlPatternFieldModel[], szServiceName2_UnoControlPatternFieldModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFormattedField[], szServiceName2_UnoControlFormattedField[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFormattedFieldModel[], szServiceName2_UnoControlFormattedFieldModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlProgressBar[], szServiceName2_UnoControlProgressBar[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlProgressBarModel[], szServiceName2_UnoControlProgressBarModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlScrollBar[], szServiceName2_UnoControlScrollBar[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlScrollBarModel[], szServiceName2_UnoControlScrollBarModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFixedLine[], szServiceName2_UnoControlFixedLine[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFixedLineModel[], szServiceName2_UnoControlFixedLineModel[];
-extern const sal_Char __FAR_DATA szServiceName_PrinterServer[], szServiceName2_PrinterServer[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlRoadmap[], szServiceName2_UnoControlRoadmap[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlRoadmapModel[], szServiceName2_UnoControlRoadmapModel[];
-
-extern const sal_Char __FAR_DATA szServiceName_UnoSpinButtonControl[], szServiceName_UnoSpinButtonModel[];
-
-extern const sal_Char __FAR_DATA szServiceName_TreeControl[];
-extern const sal_Char __FAR_DATA szServiceName_TreeControlModel[];
-extern const sal_Char __FAR_DATA szServiceName_MutableTreeDataModel[];
-
-extern const sal_Char __FAR_DATA szServiceName_UnoSimpleAnimationControl[], szServiceName_UnoSimpleAnimationControlModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoThrobberControl[], szServiceName_UnoThrobberControlModel[];
-extern const sal_Char __FAR_DATA szServiceName_UnoControlFixedHyperlink[], szServiceName_UnoControlFixedHyperlinkModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_Toolkit[], szServiceName2_Toolkit[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_MVCIntrospection[], szServiceName2_MVCIntrospection[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_PopupMenu[], szServiceName2_PopupMenu[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_MenuBar[], szServiceName2_MenuBar[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_Pointer[], szServiceName2_Pointer[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlContainer[], szServiceName2_UnoControlContainer[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlContainerModel[], szServiceName2_UnoControlContainerModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_TabController[], szServiceName2_TabController[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_TabControllerModel[], szServiceName2_TabControllerModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlDialog[], szServiceName2_UnoControlDialog[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlDialogModel[], szServiceName2_UnoControlDialogModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlEdit[], szServiceName2_UnoControlEdit[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlEditModel[], szServiceName2_UnoControlEditModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFileControl[], szServiceName2_UnoControlFileControl[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFileControlModel[], szServiceName2_UnoControlFileControlModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlButton[], szServiceName2_UnoControlButton[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlButtonModel[], szServiceName2_UnoControlButtonModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlImageButton[], szServiceName2_UnoControlImageButton[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlImageButtonModel[], szServiceName2_UnoControlImageButtonModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlImageControl[], szServiceName2_UnoControlImageControl[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlImageControlModel[], szServiceName2_UnoControlImageControlModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlRadioButton[], szServiceName2_UnoControlRadioButton[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlRadioButtonModel[], szServiceName2_UnoControlRadioButtonModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlCheckBox[], szServiceName2_UnoControlCheckBox[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlCheckBoxModel[], szServiceName2_UnoControlCheckBoxModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlListBox[], szServiceName2_UnoControlListBox[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlListBoxModel[], szServiceName2_UnoControlListBoxModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlComboBox[], szServiceName2_UnoControlComboBox[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlComboBoxModel[], szServiceName2_UnoControlComboBoxModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFixedText[], szServiceName2_UnoControlFixedText[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFixedTextModel[], szServiceName2_UnoControlFixedTextModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlGroupBox[], szServiceName2_UnoControlGroupBox[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlGroupBoxModel[], szServiceName2_UnoControlGroupBoxModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlDateField[], szServiceName2_UnoControlDateField[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlDateFieldModel[], szServiceName2_UnoControlDateFieldModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlTimeField[], szServiceName2_UnoControlTimeField[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlTimeFieldModel[], szServiceName2_UnoControlTimeFieldModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlNumericField[], szServiceName2_UnoControlNumericField[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlNumericFieldModel[], szServiceName2_UnoControlNumericFieldModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlCurrencyField[], szServiceName2_UnoControlCurrencyField[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlCurrencyFieldModel[], szServiceName2_UnoControlCurrencyFieldModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlPatternField[], szServiceName2_UnoControlPatternField[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlPatternFieldModel[], szServiceName2_UnoControlPatternFieldModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFormattedField[], szServiceName2_UnoControlFormattedField[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFormattedFieldModel[], szServiceName2_UnoControlFormattedFieldModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlProgressBar[], szServiceName2_UnoControlProgressBar[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlProgressBarModel[], szServiceName2_UnoControlProgressBarModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlScrollBar[], szServiceName2_UnoControlScrollBar[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlScrollBarModel[], szServiceName2_UnoControlScrollBarModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFixedLine[], szServiceName2_UnoControlFixedLine[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFixedLineModel[], szServiceName2_UnoControlFixedLineModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_PrinterServer[], szServiceName2_PrinterServer[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlRoadmap[], szServiceName2_UnoControlRoadmap[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlRoadmapModel[], szServiceName2_UnoControlRoadmapModel[];
+
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoSpinButtonControl[], szServiceName_UnoSpinButtonModel[];
+
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_TreeControl[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_TreeControlModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_MutableTreeDataModel[];
+
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoSimpleAnimationControl[], szServiceName_UnoSimpleAnimationControlModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoThrobberControl[], szServiceName_UnoThrobberControlModel[];
+extern SAL_DLLPUBLIC_EXPORT const sal_Char __FAR_DATA szServiceName_UnoControlFixedHyperlink[], szServiceName_UnoControlFixedHyperlinkModel[];
 
 // ExtUnoWrapper:
-extern const char __FAR_DATA szServiceName_ImageProducer[], szServiceName2_ImageProducer[];
+extern SAL_DLLPUBLIC_EXPORT const char __FAR_DATA szServiceName_ImageProducer[], szServiceName2_ImageProducer[];
 
 
 
