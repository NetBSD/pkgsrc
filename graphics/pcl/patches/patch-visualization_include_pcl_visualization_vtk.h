$NetBSD: patch-visualization_include_pcl_visualization_vtk.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/vtk.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/include/pcl/visualization/vtk.h
@@ -38,135 +38,17 @@
  *
  */
 
-#pragma once
 
-#if defined __GNUC__
-#pragma GCC system_header
-#ifdef __DEPRECATED
-#undef __DEPRECATED
-#define __DEPRECATED_DISABLED__
-#endif
-#endif
+/* The above header kept intact just for pkgsrc patching that does
+ * not like the Id bit. */
 
-#include <vtkVersion.h>
-#include <vtkAppendPolyData.h>
-#include <vtkAssemblyPath.h>
-#include <vtkAxesActor.h>
-#include <vtkActor.h>
-#include <vtkBoxRepresentation.h>
-#include <vtkBoxWidget.h>
-#include <vtkBoxWidget2.h>
-#include <vtkCellData.h>
-#include <vtkMath.h>
-#include <vtkLoopSubdivisionFilter.h>
-#include <vtkLineSource.h>
-#include <vtkLegendScaleActor.h>
-#include <vtkLightKit.h>
-#include <vtkPlatonicSolidSource.h>
-#include <vtkPropPicker.h>
-#include <vtkGeneralTransform.h>
-#include <vtkSmartPointer.h>
-#include <vtkDataSet.h>
-#include <vtkDataSetSurfaceFilter.h>
-#include <vtkExecutive.h>
-#include <vtkPolygon.h>
-#include <vtkPointPicker.h>
-#include <vtkUnstructuredGrid.h>
-#include <vtkConeSource.h>
-#include <vtkDiskSource.h>
-#include <vtkPlaneSource.h>
-#include <vtkSphereSource.h>
-#include <vtkIdentityTransform.h>
-#include <vtkTransform.h>
-#include <vtkTransformPolyDataFilter.h>
-#include <vtkTubeFilter.h>
-#include <vtkCubeSource.h>
-#include <vtkAxes.h>
-#include <vtkFloatArray.h>
-#include <vtkPointData.h>
-#include <vtkPolyData.h>
-#include <vtkPolyDataReader.h>
-#include <vtkPolyDataMapper.h>
-#include <vtkDataSetMapper.h>
-#include <vtkCellArray.h>
-#include <vtkCommand.h>
-#include <vtkCellLocator.h>
-#include <vtkPLYReader.h>
-#include <vtkTransformFilter.h>
-#include <vtkPolyLine.h>
-#include <vtkVectorText.h>
-#include <vtkFollower.h>
-#include <vtkCallbackCommand.h>
-#include <vtkInteractorStyle.h>
-#include <vtkInformationVector.h>
-#include <vtkDataArray.h>
-#include <vtkUnsignedCharArray.h>
-#include <vtkPoints.h>
-#include <vtkRendererCollection.h>
-#include <vtkPNGWriter.h>
-#include <vtkWindowToImageFilter.h>
-#include <vtkInteractorStyleTrackballCamera.h>
-#include <vtkProperty.h>
-#include <vtkCamera.h>
-#include <vtkObjectFactory.h>
-#include <vtkScalarBarActor.h>
-#include <vtkScalarsToColors.h>
-#include <vtkClipPolyData.h>
-#include <vtkPlanes.h>
-#include <vtkImageImport.h>
-#include <vtkImageViewer.h>
-#include <vtkInteractorStyleImage.h>
-#include <vtkImageFlip.h>
-#include <vtkTIFFWriter.h>
-#include <vtkBMPWriter.h>
-#include <vtkJPEGWriter.h>
-#include <vtkImageViewer2.h>
-#include <vtkRenderWindow.h>
-#include <vtkXYPlotActor.h>
-#include <vtkTextProperty.h>
-#include <vtkProperty2D.h>
-#include <vtkFieldData.h>
-#include <vtkDoubleArray.h>
-#include <vtkLODActor.h>
-#include <vtkPolyDataWriter.h>
-#include <vtkTextActor.h>
-#include <vtkCleanPolyData.h>
-#include <vtkRenderer.h>
-#include <vtkObject.h>
-#include <vtkOrientationMarkerWidget.h>
-#include <vtkImageReslice.h>
-#include <vtkImageChangeInformation.h>
-#include <vtkImageCanvasSource2D.h>
-#include <vtkImageBlend.h>
-#include <vtkImageStencilData.h>
-#include <vtkRenderWindowInteractor.h>
-#include <vtkChartXY.h>
-#include <vtkPlot.h>
-#include <vtkTable.h>
-#include <vtkContextView.h>
-#include <vtkContextScene.h>
-#include <vtkColorSeries.h>
-#include <vtkAxis.h>
-#include <vtkSelection.h>
-
-#include <vtkHardwareSelector.h>
-
-#include <vtkTriangle.h>
-#include <vtkWorldPointPicker.h>
-
-#include <vtkInteractorStyleRubberBandPick.h>
-#include <vtkInteractorStyleTrackballActor.h>
-#include <vtkAreaPicker.h>
-#include <vtkExtractGeometry.h>
-#include <vtkExtractPolyDataGeometry.h>
-#include <vtkVertexGlyphFilter.h>
-#include <vtkIdFilter.h>
-#include <vtkIdTypeArray.h>
-#include <vtkImageReader2Factory.h>
-#include <vtkImageReader2.h>
-#include <vtkImageData.h>
+/*
+ * SPDX-License-Identifier: BSD-3-Clause
+ *
+ *  Point Cloud Library (PCL) - www.pointclouds.org
+ *  Copyright (c) 2020-, Open Perception
+ *
+ *  All rights reserved
+ */
 
-#if defined __GNUC__ && defined __DEPRECATED_DISABLED__
-#define __DEPRECATED
-#undef __DEPRECATED_DISABLED__
-#endif
+PCL_DEPRECATED_HEADER(1, 14, "Use required vtk includes instead.")
